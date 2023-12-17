select p.name from people as p
join stars as s on s.person_id=p.id
join movies as m on s.movie_id=m.id
where m.title="Toy Story";