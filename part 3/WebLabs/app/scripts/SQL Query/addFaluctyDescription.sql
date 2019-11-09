ALTER TABLE Faculties
Add Desctiption VARCHAR(1024) DEFAULT "KPI Faculty";

UPDATE Faculties
SET Desctiption = DEFAULT