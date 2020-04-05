SELECT DISTINCT(people.name) FROM people
JOIN movies ON movies.id = stars.movie_id
JOIN stars ON stars.person_id = people.id
WHERE movies.year = 2004
ORDER BY people.birth;