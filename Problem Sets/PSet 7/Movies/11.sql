SELECT movies.title FROM people
JOIN ratings ON movies.id = ratings.movie_id
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE people.name = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;