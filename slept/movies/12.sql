select m.title from movies as m
join stars as s on s.movie_id = m.id
join people as p on s.person_id = p.id
where p.name == "Johnny Depp"
and title in (select title from movies
join stars on stars.movie_id = movies.id
join people on stars.person_id = people.id
where people.name = "Helena Bonham Carter");