# Write your MySQL query statement below
Select distinct author_id as id
From views
where author_id = viewer_id
order by author_id
