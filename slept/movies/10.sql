select p.name from people as p
join directors as d on d.person_id=p.id
join movies as m on d.movie_id=m.id
join ratings as r on r.movie_id=m.id
where r.rating >= 9;