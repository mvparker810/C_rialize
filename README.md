# C_rialize
A single-header C library designed to serialize and deserialize composite types into JSON with minimal setup.

## Features

- Single header library.
- Small codebase.
- Focus on flexibility and simplicity.
- No dependencies.

## Building

C_rialize is entirely self-contained into 'crialize.h'. You can use it in one of two modes:

### Header mode
By default, simply including the header gives you access to the declarations.
```c
#include "crialize.h"
```
This mode is used when the API must be referenced across multiple scripts.

### Implementation Mode
To Include the 
The implementation mode requires defining the preprocessor macro
`NK_IMPLEMENTATION` in *one* .c/.cpp file before `#include`ing this file, e.g.:
```c
#define NK_IMPLEMENTATION
#include "nuklear.h"
```
IMPORTANT: Every time you include "nuklear.h" you have to define the same optional flags.
This is very important; not doing it either leads to compiler errors, or even worse, stack corruptions.


## Usage

### Serializing and Deserializing in script
-- TODO

### Creating Serializable Types
-- TODO



## TODO List
- Preprocessor flag for printing errors
- YAML implementation
- YAML or JSON flag

## Credits
- TODO

## Liscence
- TODO