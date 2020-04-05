SELECT COUNT(movies.title)
FROM movies JOIN ratings
ON movies.title and ratings.rating
WHERE ratings.rating = 10.0;