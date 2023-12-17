select m.title from movies as m
join stars as s on s.movie_id=m.id
join people as p on s.person_id=p.id
join ratings as r on r.movie_id=m.id
where p.name = "Chadwick Boseman"
order by r.rating desc
limit 5;