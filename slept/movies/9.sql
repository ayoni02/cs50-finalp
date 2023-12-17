select distinct p.name from people as p
join stars as s on s.person_id=p.id
join movies as m on s.movie_id=m.id
join ratings as r on r.movie_id=m.id
where m.year=2004
order by p.birth;