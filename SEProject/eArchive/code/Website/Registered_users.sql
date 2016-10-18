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




CREATE TABLE IF NOT EXISTS `Registed_Users` (
  id int(9) NOT NULL auto_increment,
  name varchar(20)NOT NULL,
  password char(32) not null,
  age int(3) NOT NULL ,
  Location varchar(30),
  email varchar(40)NOT NULL,
  creat_time varchar(40)NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


insert into registed_users (id,name,password,age,Location,email,creat_time) values ('0001','tianzhe',MD5('8888'),'18','NJ','tianzhewang@126.com',now())





