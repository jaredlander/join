#' Unique Characters
#'
#' Find unique values of a character vector
#'
#' A new algorithm for finding the unique values of a character vector
#'
#' It is dispatched to by \code{\link{unique}} and it calls a c++ function that uses a hash
#'
#' @aliases unique.character
#' @author Jared P. Lander
#' @seealso \code{\link{unique}} \code{\link{unique.integer}} \code{\link{unique.numeric}}
#' @param x Character vector
#' @return A character vector of the unique values
#' www.jaredlander.com
#' @export unique.character
#' @keywords unique
#' @useDynLib join
#' @examples
#' 
#' mytext <- c("a", "b", "a", "jared", "b", "ben", "Jared")
#' unique.character(mytext)
#'
unique.character <- function(x)
{
    .Call("unique_str", x, PACKAGE="join")
}



#' Unique Numeric
#'
#' Find unique values of a numeric vector
#'
#' A new algorithm for finding the unique values of a numeric vector
#'
#' It is dispatched to by \code{\link{unique}} and it calls a c++ function that uses a hash
#'
#' A little cheating is done since then hash algorithm does not accept float keys.  So the vector is converted to character, the character uniqueing is done, then the result is converted back to numeric.
#'
#' @aliases unique.numeric
#' @author Jared P. Lander
#' @seealso \code{\link{unique}} \code{\link{unique.integer}} \code{\link{unique.character}}
#' @param x Numeric vector
#' @return A numeric vector of the unique values
#' www.jaredlander.com
#' @export unique.numeric
#' @keywords unique
#' @examples
#' 
#' mynum <- c(3.2, 4, 3.20, 7, 8.6, 4, 4, 3)
#' unique(mynum)
#'
unique.numeric <- function(x)
{
    x <- as.character(x)
    x <- .Call("unique_str", x, PACKAGE="join")
    x <- as.numeric(x)
    return(x)
}


#' Unique Integer
#'
#' Find unique values of a integer vector
#'
#' A new algorithm for finding the unique values of a integer vector
#'
#' It is dispatched to by \code{\link{unique}} and it calls a c++ function that uses a hash
#'
#' @aliases unique.numeric
#' @author Jared P. Lander
#' @seealso \code{\link{unique}} \code{\link{unique.numeric}} \code{\link{unique.character}}
#' @param x Integer vector
#' @return An integer vector of the unique values
#' www.jaredlander.com
#' @export unique.integer
#' @keywords unique
#' @examples
#' 
#' myint <- c(3, 4, 3, 7, 8, 4, 4, 3)
#' unique(myint)
#'
unique.integer <- function(x)
{
    .Call("unique_32", x, PACKAGE="join")
}


# dyn.load("C:/Users/Jared/join/src/unique.dll")
# 
# unique(mytext)
# dyn.unload("C:/Users/Jared/join/src/unique.dll")