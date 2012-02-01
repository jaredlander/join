\name{unique.character}
\alias{unique.character}
\title{Unique Characters}
\usage{
  unique.character(x)
}
\arguments{
  \item{x}{Character vector}
}
\value{
  A character vector of the unique values
  www.jaredlander.com
}
\description{
  Find unique values of a character vector
}
\details{
  A new algorithm for finding the unique values of a
  character vector

  It is dispatched to by \code{\link{unique}} and it calls
  a c++ function that uses a hash
}
\examples{
mytext <- c("a", "b", "a", "jared", "b", "ben", "Jared")
unique.character(mytext)
}
\author{
  Jared P. Lander
}
\seealso{
  \code{\link{unique}} \code{\link{unique.integer}}
  \code{\link{unique.numeric}}
}
\keyword{unique}

