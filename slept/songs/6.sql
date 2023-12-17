SELECT
    s.name
FROM
    songs AS s
JOIN artists as a on s.artist_id == a.id
WHERE a.name == 'Post Malone';