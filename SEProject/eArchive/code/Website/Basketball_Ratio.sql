-- phpMyAdmin SQL Dump
-- version 4.2.8.1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: 2015-10-25 23:32:51
-- 服务器版本： 5.6.20
-- PHP Version: 5.4.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


--
-- Database: `hma2014`
--
-- 建立注册系统人员的信息
-- --------------------------------------------------------

--
-- 表的结构 `ANEW`
--




CREATE TABLE IF NOT EXISTS `Basketball_ratio` (
  id int(9) NOT NULL auto_increment,
  tweet_id bigint(20) unsigned NOT NULL,
  inType int(1) not null,
  inserttime varchar(40)NOT NULL,
  otherInfo varchar(30),
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('1','00006611','0','2015-10-25 22:12:04','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('2','00006611','1','2015-10-25 22:12:03','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('3','00006611','0','2015-10-25 22:12:05','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('4','00006611','1','2015-10-25 22:12:03','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('5','00006611','0','2015-10-25 22:12:03','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('6','00006611','1','2015-10-25 22:12:03','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('7','00006611','1','2015-10-25 22:12:03','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('8','00006611','0','2015-10-25 22:12:03','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('9','00006611','0','2015-10-25 22:12:03','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('10','00006611','0','2015-10-25 22:12:03','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('11','00006611','1','2015-10-25 22:12:03','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('12','00006611','0','2015-10-25 22:12:03','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('13','00006611','0','2015-10-25 22:12:07','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('14','00006611','1','2015-10-25 22:12:03','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('15','00006611','1','2015-10-25 22:12:03','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('16','00006611','0','2015-10-25 22:12:03','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('17','00006611','0','2015-10-25 22:12:03','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('18','00006611','1','2015-10-25 22:12:12','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('19','00006611','0','2015-10-25 22:12:03','');
insert into Basketball_ratio (id,tweet_id,inType,inserttime,otherInfo) values ('20','00006611','0','2015-10-25 22:12:03','');




