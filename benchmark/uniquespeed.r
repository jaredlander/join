require(rbenchmark)
# create fake data
source("C:/users/Jared/join/benchmark/data.r")

# location of .dll's
src <- "C:/users/Jared/join/src"

# load library for integers and check if the function is loaded
dyn.load(file.path(src, "intwin.dll"))
is.loaded("unique_32")

# simeple test
.Call("unique_32", c(1, 2, 1, 1, 3, 2))

# compare to builtin unique function
benchmark(.Call("unique_32", int.100.100000), unique(int.100.100000))
benchmark(.Call("unique_32", int.1000.100000), unique(int.1000.100000))
benchmark(.Call("unique_32", int.10000.100000), unique(int.10000.100000))
benchmark(.Call("unique_32", int.100000.100000), unique(int.100000.100000))

# unload dll
dyn.unload(file.path(src, "intwin.dll"))
is.loaded("unique_32")



# load library for characters and check if the function is loaded
dyn.load(file.path(src, "strtry.dll"))
is.loaded("unique_str")

# simple test
.Call("unique_str", c("a", "b", "a", "a", "c", "b", "jared", "bob", "jared"))

benchmark(.Call("unique_str", char.100.100000), unique(char.100.100000))
benchmark(.Call("unique_str", char.1000.100000), unique(char.1000.100000))
benchmark(.Call("unique_str", char.10000.100000), unique(char.10000.100000))
benchmark(.Call("unique_str", char.100000.100000), unique(char.100000.100000))

dyn.unload(file.path(src, "strtry.dll"))