[@bs.module "./locale-en"] external locale : string => string = "default";

let translate = (message: string) => locale(message);