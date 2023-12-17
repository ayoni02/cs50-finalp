SELECT
    AVG(s.energy)
FROM
    songs as s
join artists as a
on s.artist_id = a.id
where a.name == 'Drake'
group by a.name;