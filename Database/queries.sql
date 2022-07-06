--Change Column Type
alter table dionysus.episode
    alter column episode_number TYPE SERIAL;

-- Make Column Nullable
alter table dionysus.episode
    alter column episode_number DROP NOT NULL;

-- Rename Column
-- alter table dionysus.episode
  --  rename column episode_wallpapaer to episode_wallpaper;

-- Insert A User
insert into dionysus."user"(user_id, user_name, user_email, user_password)
values (default, 'Abbas', 'abbas.mj.srour@gmail.com', default);

-- Insert An Actor
insert into dionysus.actor default values;
select * from dionysus.actor;

-- Insert A Genre
insert into dionysus.genre(genre_id, genre_name)
VALUES (default,'Horror');

-- Insert A Movie
insert into dionysus.movie(movie_id, movie_name, movie_wallpaper, movie_location, imdb_link)
values (default,'Avengers',default,default,default);
select *
from dionysus.movie;

-- Insert A TV Series
insert into dionysus.series (series_id, series_name, series_wallpaper) values (default, 'Friends', default);
select *
    from dionysus.series;

-- Insert An Episode With Its corresponding TV-Series Foreign Key
insert into dionysus.episode(episode_id, series_id, episode_name, episode_wallpaper, episode_number, episode_location)
select default, dionysus.series.series_id, default, default,default,default
    from dionysus.series
        where dionysus.series.series_id = 1;
select * from dionysus.episode;

-- Delete A User
delete from dionysus."user"
where dionysus."user".user_name = 'abbas';

-- Clear Movie History
delete from dionysus.movie_history;

-- Trigger And A Function to make the episode_wallpaper same
-- as the one of the series if the episode wallpaper doesn't exist
CREATE OR REPLACE FUNCTION dionysus.change_wallpaper(targeted_episode_id BIGINT)
RETURNS varchar
    LANGUAGE plpgsql
    AS
    $$
    Declare wallpaper varchar;
    BEGIN
        UPDATE dionysus.episode
        SET episode_wallpaper = dionysus.series.series_wallpaper
        WHERE dionysus.episode.episode_id = dionysus.series.series_wallpaper
          and dionysus.episode.episode_id = targeted_episode_id;
/*        Select dionysus.series.series_wallpaper
        INTO wallpaper
        FROM dionysus.series
        WHERE dionysus.series.series_id = (Select dionysus.episode.series_id
                                           from dionysus.episode
                                           where dionysus.episode.episode_id = targeted_episode_id);*/
        END;
    $$;
-- TODO: FIX THIS
CREATE TRIGGER defaultWallpaper
    AFTER INSERT
    ON dionysus.episode
    NOT DEFERRABLE
    FOR EACH ROW
    WHEN ( dionysus.episode.episode_wallpaper is null )
    EXECUTE FUNCTION dionysus.change_wallpaper(episode.episode_id);

-- The User Watched A Movie
insert into dionysus.movie_history
select dionysus."user".user_id, dionysus.movie.movie_id
    from dionysus."user", dionysus.movie
        where dionysus."user".user_name = 'abbas' and dionysus.movie.movie_name = 'Avengers';
select * from dionysus.movie_history;




-- TODO
-- 1- Change Foreign Keys To Delete On Delete
-- 2- Add Trigger For Episode Wallpaper
-- 3- Add sequence to episode_number
-- 4- Make episode_number nullable???
-- 5- Create View For User History
