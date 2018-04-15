type state = {
  books: option(array(BookModel.model))
};

type actions = 
  | Loaded(array(BookModel.model));

let component = ReasonReact.reducerComponent("BookContainer");

let make = (~bookTitle, _children) => {
  ...component,
  initialState: () => {
    books: None
  },
  reducer: (action, _) => {
    switch (action) {
      | Loaded(books) => ReasonReact.Update({ books: Some(books) });
    }
  },
  willReceiveProps: (self) => {
    let handleBooksLoaded = self.reduce(postData => Loaded(postData));

    BookService.search(~text = bookTitle)
      |> Js.Promise.then_(data => {
        handleBooksLoaded(data);
        data |> Js.Promise.resolve
      });
  
    self.state;
  },
  render: ({ state }) => {
    let books = switch (state.books) {
      | Some(books) => ReasonReact.arrayToElement(Array.map(
          (book: BookModel.model) => {
            <Book key={book.id} book={book}/>
          },
          books
        ))
      | None => ReasonReact.stringToElement(Locale.translate("COMMON.NO_DATA"))
    };
    
    <div className="grid grid-row books">
      { books }
    </div>
  }
}