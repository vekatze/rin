# rin

`rin` is a libcurl-based HTTP client library for the [Neut](https://vekatze.github.io/neut/) programming language.

## Installation

```sh
neut get rin https://github.com/vekatze/rin/raw/main/archive/0-1-5.tar.zst
```

## Prerequisites

Install `libcurl` on your machine and add something like the below to your app's `module.ens`:

```ens
{
  // ..
  target {
    test {
      main "test.nt",
      // ↓ add
      build-option [
        "$(pkg-config libcurl --libs --cflags)",
      ],
      // ↑ add
    },
  },
  zen {
    // ↓ add
    build-option [
      "$(pkg-config libcurl --libs --cflags)",
    ],
    // ↑ add
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
