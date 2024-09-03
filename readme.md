# rin

`rin` is a libcurl-based HTTP client for the [Neut](https://vekatze.github.io/neut/) programming language.

## Example

The main interface of `rin` is `perform: (request, config) -> either(error, response)`:

```neut
define main(): unit {
  let result =
    // the function `perform` performs an HTTP request
    perform(
      // construct the request
      Request of {
        method = POST,
        path = *"/path/to/something",
        fields = {
          [
            Field(*"Content-Type", *"application/json"),
            Field(*"x-my-extension", *"foo"),
          ]
        },
        body = *"Lorem ipsum",
      },
      // configure how the request is performed
      Config of {
        host = "https://example.com",
        // read the response body using a buffer with an initial size of 1024 bytes (doubling the size when necessary)
        initial-buffer-size = 1024,
        options = {
          [
            Follow-Location(True),
            Timeout(123),
          ]
        },
      },
    )
  in
  match result {
  | Right(response) =>
    let Response of {status-code, body, fields} = response in
    printf("success:\n{}\n", [body])
  | Left(e) =>
    printf("failure:\n{}\n", [show-error(e)])
  }
}
```
