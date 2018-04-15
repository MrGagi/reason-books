let component = ReasonReact.statelessComponent("Book");

let make = (~book: BookModel.model, _children) => {
  ...component,
  render: (self) => {
    <div className="box">
      <p className="title">{ ReasonReact.stringToElement(book.title) }</p>
    </div>
  }
};