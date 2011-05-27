-- phpMyAdmin SQL Dump
-- version 3.3.8.1
-- http://www.phpmyadmin.net
--
-- Хост: localhost
-- Время создания: Май 06 2011 г., 14:44
-- Версия сервера: 5.1.51
-- Версия PHP: 5.3.6-pl0-gentoo

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- База данных: `4med`
--

-- --------------------------------------------------------

--
-- Структура таблицы `Department`
--

CREATE TABLE IF NOT EXISTS `Department` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `title` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `title` (`title`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

--
-- Дамп данных таблицы `Department`
--


-- --------------------------------------------------------

--
-- Структура таблицы `Drug`
--

CREATE TABLE IF NOT EXISTS `Drug` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `title` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `title` (`title`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 AUTO_INCREMENT=3 ;

--
-- Дамп данных таблицы `Drug`
--

INSERT INTO `Drug` (`id`, `title`) VALUES
(1, 'Первый медикамент'),
(2, 'Второй медикамент');

-- --------------------------------------------------------

--
-- Структура таблицы `Recipient`
--

CREATE TABLE IF NOT EXISTS `Recipient` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idDepartment` tinyint(4) NOT NULL,
  `fio` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `fio` (`fio`),
  KEY `idDepartment` (`idDepartment`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

--
-- Дамп данных таблицы `Recipient`
--


-- --------------------------------------------------------

--
-- Структура таблицы `Registration`
--

CREATE TABLE IF NOT EXISTS `Registration` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `idDrug` int(11) NOT NULL,
  `idRecipient` int(11) DEFAULT NULL,
  `when` date NOT NULL,
  `amount` tinyint(4) NOT NULL,
  `received` tinyint(1) NOT NULL,
  `balance` tinyint(4) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `idDrug` (`idDrug`),
  KEY `idRecipient` (`idRecipient`),
  KEY `when` (`when`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

--
-- Дамп данных таблицы `Registration`
--

