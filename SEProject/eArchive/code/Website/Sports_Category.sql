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
-- 为了区分各个运动，简历如下表格：basketball，volleyball，running， football，iceball，golf， skating， boxing。 总表还是tweeter, 以 tweet_id来关联。
-- --------------------------------------------------------

--
-- 表的结构 `ANEW`
--


CREATE TABLE IF NOT EXISTS `tweets_basketball` (
  `tweet_id` bigint(20) unsigned NOT NULL,
  `tweet_text` varchar(160) NOT NULL,
  `entities` text NOT NULL,
  `created_at` datetime NOT NULL,
  `geo_lat` decimal(10,5) DEFAULT NULL,
  `geo_long` decimal(10,5) DEFAULT NULL,
  `user_id` int(10) unsigned NOT NULL,
  `screen_name` char(20) NOT NULL,
  `name` varchar(40) DEFAULT NULL,
  `profile_image_url` varchar(200) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `tweets_boxing` (
  `tweet_id` bigint(20) unsigned NOT NULL,
  `tweet_text` varchar(160) NOT NULL,
  `entities` text NOT NULL,
  `created_at` datetime NOT NULL,
  `geo_lat` decimal(10,5) DEFAULT NULL,
  `geo_long` decimal(10,5) DEFAULT NULL,
  `user_id` int(10) unsigned NOT NULL,
  `screen_name` char(20) NOT NULL,
  `name` varchar(40) DEFAULT NULL,
  `profile_image_url` varchar(200) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


CREATE TABLE IF NOT EXISTS `tweets_football` (
  `tweet_id` bigint(20) unsigned NOT NULL,
  `tweet_text` varchar(160) NOT NULL,
  `entities` text NOT NULL,
  `created_at` datetime NOT NULL,
  `geo_lat` decimal(10,5) DEFAULT NULL,
  `geo_long` decimal(10,5) DEFAULT NULL,
  `user_id` int(10) unsigned NOT NULL,
  `screen_name` char(20) NOT NULL,
  `name` varchar(40) DEFAULT NULL,
  `profile_image_url` varchar(200) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
