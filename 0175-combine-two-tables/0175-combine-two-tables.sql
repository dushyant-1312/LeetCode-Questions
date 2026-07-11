# Write your MySQL query statement below

with temp as(
    select firstName, lastName, city, state from person p left join address a on p.personId = a.personId
)
select firstName, lastName, city, state from temp;