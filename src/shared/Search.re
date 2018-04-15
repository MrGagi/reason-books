type state = {
  text: string,
  results: option(array(BookModel.model))
};

type actions = 
  | Loaded(array(BookModel.model))
  | Change(string);

let component = ReasonReact.reducerComponent("Search");

let make = (~onTextChange, _children) => {
  ...component,
  initialState: () => {
    text: "",
    results: None
  },
  reducer: (action, state) => {
    switch(action) {
      | Loaded(books) => ReasonReact.Update({ ...state, results: Some(books) })
      | Change(text: string) => {
        onTextChange(text);
        ReasonReact.NoUpdate;
      }
    }
  },
  render: ({ send }) => {
    <div className="search">
      <input _type="text"
        placeholder={ Locale.translate("PLACEHOLDERS.SEARCH") }
        onChange=(event => send(Change(
          ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value
        )))
      />
    </div>
  }
}