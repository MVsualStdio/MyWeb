create user 'xie'@'%' identified by '123456'; 
grant all privileges on *.* to 'xie'@'%' with grant option; 
ALTER user 'xie'@'%' IDENTIFIED WITH mysql_native_password BY '123456';
flush privileges; 


create database if not exists web;
use web;
create table if not exists web_user(
    user_id int unsigned auto_increment,
    user_name varchar(100) not null,
    user_paswd varchar(100) not null,
    primary key (user_id)
);
insert into web_user (user_name,user_paswd) values ("xie","123");