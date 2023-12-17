select r.rating, m.title
from ratings as r join movies as m
on r.movie_id=m.id
where m.year=2010
order by r.rating desc, m.title asc;