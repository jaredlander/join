\name{unique.numeric}
\alias{unique.numeric}
\title{Unique Numeric}
\usage{
  unique.numeric(x)
}
\arguments{
  \item{x}{Numeric vector}
}
\value{
  A numeric vector of the unique values www.jaredlander.com
}
\description{
  Find unique values of a numeric vector
}
\details{
  A new algorithm for finding the unique values of a
  numeric vector

  It is dispatched to by \code{\link{unique}} and it calls
  a c++ function that uses a hash

  A little cheating is done since then hash algorithm does
  not accept float keys.  So the vector is converted to
  character, the character uniqueing is done, then the
  result is converted back to numeric.
}
\examples{
mynum <- c(3.2, 4, 3.20, 7, 8.6, 4, 4, 3)
unique(mynum)
}
\author{
  Jared P. Lander
}
\seealso{
  \code{\link{unique}} \code{\link{unique.integer}}
  \code{\link{unique.character}}
}
\keyword{unique}

