CREATE DATABASE LabsDB;
USE LabsDB;

CREATE TABLE Faculties
(
    Id INT PRIMARY KEY AUTO_INCREMENT,
    Name VARCHAR(128) NOT NULL
);

CREATE TABLE Classes
(
    Id INT PRIMARY KEY AUTO_INCREMENT,
    Cipher VARCHAR(128) NOT NULL,
    Code INT NOT NULL,
    FacultyId INT NOT NULL,
    FOREIGN KEY (FacultyId) REFERENCES Faculties(Id) ON DELETE NO ACTION
);

CREATE TABLE Students
(
    Id INT PRIMARY KEY AUTO_INCREMENT,
    FirstName VARCHAR(128) NOT NULL,
    LastName VARCHAR(128) NOT NULL,
    MiddleName VARCHAR(128) NOT NULL,
    Birthday DATE NOT NULL,
    ClassID INT NOT NULL,
    FOREIGN KEY (ClassId) REFERENCES Classes(Id) ON DELETE NO ACTION
);