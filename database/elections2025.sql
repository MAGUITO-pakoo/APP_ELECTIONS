-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3308
-- Généré le : ven. 17 oct. 2025 à 05:54
-- Version du serveur : 10.4.32-MariaDB
-- Version de PHP : 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `elections2025`
--

-- --------------------------------------------------------

--
-- Structure de la table `candidats`
--

CREATE TABLE `candidats` (
  `id` int(11) UNSIGNED NOT NULL,
  `nom` varchar(50) DEFAULT NULL,
  `prenom` varchar(50) DEFAULT NULL,
  `parti` varchar(100) DEFAULT NULL,
  `date_naissance` date DEFAULT NULL,
  `cotion` decimal(10,0) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `candidats`
--

INSERT INTO `candidats` (`id`, `nom`, `prenom`, `parti`, `date_naissance`, `cotion`) VALUES
(1, 'Biya', 'Paul', 'RDPC', '1933-02-13', 50000000),
(2, 'Kah Walla', 'Edith', 'CPP', '1965-02-28', 50000000),
(3, 'Kamto', 'Maurice', 'MRC', '1954-02-15', 50000000),
(4, 'Libii', 'Cabral', 'PCRN', '1980-03-29', 50000000),
(5, 'Ndam Njoya', 'Adamou', 'UDC', '1942-05-08', 50000000),
(6, 'Ateki', 'Seta Caxton', 'PAL', '0000-00-00', 50000000),
(7, 'Bello Bouba', 'Maïgari', 'UNDP', '0000-00-00', 50000000),
(8, 'Bouhga-Hagbe', 'Jacques', 'MCNC', '0000-00-00', 50000000),
(9, 'Tchiroma', 'Issa Bakary', 'FSNC', '0000-00-00', 50000000),
(10, 'Iyodi', 'Hiram Samuel', 'FDC', '0000-00-00', 50000000),
(11, 'Kwemo', 'Pierre', 'UMS', '0000-00-00', 50000000),
(12, 'Matomba', 'Serge Espoir', 'PURS', '0000-00-00', 50000000),
(13, 'Muna', 'Akere', 'Univers', '0000-00-00', 50000000);

-- --------------------------------------------------------

--
-- Structure de la table `electeurs`
--

CREATE TABLE `electeurs` (
  `id` int(10) NOT NULL,
  `nom` varchar(50) DEFAULT NULL,
  `prenom` varchar(50) DEFAULT NULL,
  `age` int(3) DEFAULT NULL,
  `quartier` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `candidats`
--
ALTER TABLE `candidats`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `electeurs`
--
ALTER TABLE `electeurs`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `candidats`
--
ALTER TABLE `candidats`
  MODIFY `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=22;

--
-- AUTO_INCREMENT pour la table `electeurs`
--
ALTER TABLE `electeurs`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
