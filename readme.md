# rin

`rin` is a libcurl-based HTTP client library for the [Neut](https://vekatze.github.io/neut/) programming language.

## Prerequisites

Install `libcurl` on your machine (if not exists) and add something like the below to your `module.ens`:

```ens
{
  // ..
  target {
    test {
      main "test.nt",
      // ↓ this
      build-option [
        "$(pkg-config libcurl --libs --cflags)",
      ],
    },
  },
  zen {
    // ↓ this
    build-option [
      "$(pkg-config libcurl --libs --cflags)",
    ],
  },
  // ..
}
```

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
            Field(*"x-foo", *"bar"),
          ]
        },
        body = *"Lorem ipsum",
      },
      // configure how the request is performed
      Config of {
        host = "https://example.com",
        // read the response body using a buffer with an initial size of 1024 bytes
        // (increasing the size when necessary)
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
