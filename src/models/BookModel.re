type model = {
  id: string,
  title: string
};

let decode = (json) : model => {
  Json.Decode.{
    id: json |> Json.Decode.field("id", string),
    title: json |> Json.Decode.field("volumeInfo", (json) => 
      json |> Json.Decode.field("title", string)
    )
  }
};