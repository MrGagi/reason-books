[@bs.module "./../config"] external apiKey : string = "apiKey";
[@bs.module "./../config"] external apiEndPoint : string = "apiEndPoint";

let decodeItems = (json) => {
  json |> Json.Decode.array(BookModel.decode)
};

let search = (~text: string) => {
  Js.Promise.(
    Fetch.fetch(apiEndPoint ++ "?q=" ++ text ++ "&key=" ++ apiKey)
      |> then_(Fetch.Response.json)
      |> then_(data => {
        data
          |> Json.Decode.field("items", decodeItems)
          |> resolve
      })
  )
};
