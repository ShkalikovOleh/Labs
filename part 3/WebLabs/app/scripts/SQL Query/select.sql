SELECT Students.FirstName, Students.MiddleName, Students.LastName, Students.Birthday, Classes.Cipher, Classes.Code, Faculties.Name
FROM Students
JOIN Classes ON Classes.Id = Students.ClassId
JOIN Faculties ON Faculties.Id = Classes.FacultyId;

SELECT Students.FirstName, Students.MiddleName, Students.LastName, Students.Birthday, Classes.Cipher, Classes.Code, Faculties.Name
FROM Students
JOIN Classes ON Classes.Id = Students.ClassId
JOIN Faculties ON Faculties.Id = Classes.FacultyId
ORDER BY LastName ASC
LIMIT 10;

SELECT COUNT(*) FROM Students;