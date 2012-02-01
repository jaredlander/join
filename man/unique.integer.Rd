\name{unique.integer}
\alias{unique.integer}
\alias{unique.numeric}
\title{Unique Integer}
\usage{
  unique.integer(x)
}
\arguments{
  \item{x}{Integer vector}
}
\value{
  An integer vector of the unique values
  www.jaredlander.com
}
\description{
  Find unique values of a integer vector
}
\details{
  A new algorithm for finding the unique values of a
  integer vector

  It is dispatched to by \code{\link{unique}} and it calls
  a c++ function that uses a hash
}
\examples{
myint <- c(3, 4, 3, 7, 8, 4, 4, 3)
unique(myint)
}
\author{
  Jared P. Lander
}
\seealso{
  \code{\link{unique}} \code{\link{unique.numeric}}
  \code{\link{unique.character}}
}
\keyword{unique}

