[%bs.raw {|require('./app.css')|}];

type state = {
  text: option(string)
};

type actions = 
  | TextChanged(string);

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  initialState: () => {
    text: None
  },
  reducer: (action, _) => {
    switch(action) {
      | TextChanged("") => ReasonReact.Update({ text: None })
      | TextChanged(text: string) => ReasonReact.Update({ text: Some(text) })
    }
  },
  render: ({ state, send }) => {
    let books = switch (state.text) {
      | Some(text) => <BookContainer bookTitle={text}></BookContainer>
      | None => ReasonReact.stringToElement(Locale.translate("COMMON.TYPE_SOMETHING"))
    };

    <div className="App">
      <Search onTextChange=((data: string) => send(
        TextChanged(data)
      ))/>
      { books }
    </div>
  }
};
