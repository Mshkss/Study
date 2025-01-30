use Decanat;
/* Показать в представлении студентов, сдававших сессии на «Отлично». Вывести
Ф.И.О., номер группы и семестр. Группировать по семестрам и группам. */

GO
IF (EXISTS (select * FROM sys.views where name = 'GroupList')) 
	begin
		DROP VIEW GroupList
	end
GO 
CREATE VIEW GroupList AS
	SELECT Studying.[Gradebook number] AS 'Зачетная книжка',
		   Studying.Mark AS 'Оценка',
		   Subjects.Semester AS 'Семестр',
		   Subjects.Specialty AS 'Специальность'
	from Studying
	join Subjects on Studying.ID_Subject = Subjects.ID

GO
SELECT * FROM GroupList


GO
IF (EXISTS (select * FROM sys.views where name = 'Scores')) 
	begin
		DROP VIEW Scores
	end
GO
CREATE VIEW Scores AS
	SELECT GroupList.[Зачетная книжка] AS 'Зачетная книжка',
		   SUM(CASE WHEN GroupList.Оценка = 'Зачёт' THEN 1
					WHEN GroupList.Оценка = 'Отлично' THEN 1
					--when grouplist.Оценка = 'Хорошо' THEN 0
					ELSE 0
			   END) AS 'Сумма оценок',
		   GroupList.Семестр AS 'Семестр',
		   GroupList.Специальность AS 'Специальность'
	FROM GroupList
	GROUP BY GroupList.[Зачетная книжка], GroupList.Семестр, GroupList.Специальность

GO
SELECT * FROM Scores


GO
IF (EXISTS (select * FROM sys.views where name = 'GoodStudents')) 
	begin
		DROP VIEW GoodStudents
	end
GO
CREATE VIEW GoodStudents AS
	SELECT SURNAME AS ' Фамилия',
		   STUDENTS.[First name] AS 'Имя',
		   PATRONYMIC AS 'Отчество',
		   GROUPS.Name AS 'Название группы',
		   Scores.Семестр AS 'Семестр'
	FROM STUDENTS
	JOIN GROUPS ON STUDENTS.ID_GROUP = GROUPS.ID 
	JOIN Scores ON STUDENTS.[Gradebook number] = Scores.[Зачетная книжка]
	WHERE Scores.[Сумма оценок] = (SELECT COUNT(Subjects.ID) FROM Subjects
								 WHERE Subjects.Specialty = Scores.Специальность
								 AND  Subjects.SEMESTER = Scores.Семестр)

GO
SELECT * FROM GoodStudents