select avg(r.rating) from ratings as r
join movies as m on r.movie_id = m.id
where m.year == 2012;