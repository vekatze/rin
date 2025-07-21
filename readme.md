# rin

`rin` is a libcurl-based HTTP client library for the [Neut](https://vekatze.github.io/neut/) programming language.

## Installation

### Install Prerequisites

Install `pkg-config` and `libcurl`. On Debian and Ubuntu, for example, you can install them as follows:

```sh
apt install libcurl4-openssl-dev pkg-config
```

### Add This Module to Your App

Install this module as usual:

```sh
neut get rin https://github.com/vekatze/rin/raw/main/archive/0-1-32.tar.zst
```

### Configure Your App

Add something like the following to your app's `module.ens`:

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

## Types

```neut
// Performs a request.
define perform(req: request, c: config): either(error, response)

// A configuration for a request.
data config {
| Config(
    host: &text,
    initial-buffer-size: int,
    options: list(option),
  )
}

// Possible options when performing a request.
data option {
| Follow-Location(bool)
| Timeout(int)
}

// The type of errors in `rin`.
data error {
| Curl-Error(error-code: int)
| Curl-Initialization-Error
| Curl-Header-Construction-Error
}

// Converts errors into human-readable texts.
define show-error(e: error): text
```

## Example

The main interface of `rin` is `perform: (request, config) -> either(error, response)`:

```neut
define main(): unit {
  let result =
    // the function `perform` performs an HTTP request
    perform(
      Request of {
        method := GET,
        path := *"/",
        fields := {
          [
            Field(*"My-Field", *"hoge"),
            Field(*"Content-Type", *"application/json"),
            Field(*"x-my-extension", *"Bearer 1234567890"),
          ]
        },
        body := *"Lorem ipsum",
      },
      // configure how the request is performed
      Config of {
        host := "http://localhost:8080",
        // read the response body using a buffer with an initial size of 1024 bytes
        // (increasing the size when necessary)
        initial-buffer-size := 1024,
        options := {
          [
            Follow-Location(True),
            Timeout(2),
          ]
        },
      },
    );
  match result {
  | Right(response) =>
    let Response of {status-code, body, fields} = response;
    pin body = body;
    print-line("success:");
    print-line(body);
    print-line("header:");
  | Left(e) =>
    pin error = show-error(e);
    print("failure: ");
    print-line(error);
  }
}
```
