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





CREATE TABLE IF NOT EXISTS `tweets_basketball_fea` (
  `tweet_id` bigint(20) unsigned NOT NULL,
  `typ`   int(1) NOT NULL,
  `fea1`   float NOT NULL,
  `fea2`   float NOT NULL,
  `fea3`   float NOT NULL,
  `fea4`   float NOT NULL,
  `fea5`   float NOT NULL,
  `fea6`   float NOT NULL,
  `fea7`   float NOT NULL,
  `fea8`   float NOT NULL,
  `fea9`   float NOT NULL,
  `fea10`  float NOT NULL,
  `fea11`  float NOT NULL,
  `fea12`  float NOT NULL,
  `fea13`  float NOT NULL,
  `fea14`  float NOT NULL,
  `fea15`  float NOT NULL,
  `fea16`  float NOT NULL,
  `fea17`  float NOT NULL,
  `fea18`  float NOT NULL,
  `fea19`  float NOT NULL,
  `fea20`  float NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;






CREATE TABLE IF NOT EXISTS `tweets_football_fea` (
  `tweet_id` bigint(20) unsigned NOT NULL,
  `typ`   int(1) NOT NULL,
  `fea1`   float NOT NULL,
  `fea2`   float NOT NULL,
  `fea3`   float NOT NULL,
  `fea4`   float NOT NULL,
  `fea5`   float NOT NULL,
  `fea6`   float NOT NULL,
  `fea7`   float NOT NULL,
  `fea8`   float NOT NULL,
  `fea9`   float NOT NULL,
  `fea10`  float NOT NULL,
  `fea11`  float NOT NULL,
  `fea12`  float NOT NULL,
  `fea13`  float NOT NULL,
  `fea14`  float NOT NULL,
  `fea15`  float NOT NULL,
  `fea16`  float NOT NULL,
  `fea17`  float NOT NULL,
  `fea18`  float NOT NULL,
  `fea19`  float NOT NULL,
  `fea20`  float NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;





CREATE TABLE IF NOT EXISTS `tweets_boxing_fea` (
  `tweet_id` bigint(20) unsigned NOT NULL,
  `typ`   int(1) NOT NULL,
  `fea1`   float NOT NULL,
  `fea2`   float NOT NULL,
  `fea3`   float NOT NULL,
  `fea4`   float NOT NULL,
  `fea5`   float NOT NULL,
  `fea6`   float NOT NULL,
  `fea7`   float NOT NULL,
  `fea8`   float NOT NULL,
  `fea9`   float NOT NULL,
  `fea10`  float NOT NULL,
  `fea11`  float NOT NULL,
  `fea12`  float NOT NULL,
  `fea13`  float NOT NULL,
  `fea14`  float NOT NULL,
  `fea15`  float NOT NULL,
  `fea16`  float NOT NULL,
  `fea17`  float NOT NULL,
  `fea18`  float NOT NULL,
  `fea19`  float NOT NULL,
  `fea20`  float NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


