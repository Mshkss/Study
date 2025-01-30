use Decanat;

--Создать функцию, определяющую средний бал по указанной дисциплине.
--Принимая идентификатор дисциплины, как входной параметр (например,
--ID_Disciplin), функция возвращает вещественное значение среднего балла среди
--всех студентов, сдававших экзамен

--сделать проверку на if как в 9 работе::
GO
DROP FUNCTION avgScore;

GO
CREATE FUNCTION avgScore (@ID_Discipline INT)
    RETURNS FLOAT
BEGIN
RETURN (
        SELECT CAST(SUM((CASE 
                         WHEN Studying.Mark = 'Отлично' then 5 
                         WHEN Studying.Mark = 'Хорошо' then 4 
                         WHEN Studying.Mark = 'Удовлетворительно' then 3
						 WHEN Studying.Mark = 'Зачёт' then 1
						 WHEN Studying.Mark = 'Незачёт' then 0
	                      END)) AS FLOAT) / COUNT(Studying.Mark)
          FROM decanat.dbo.Studying 
              WHERE Studying.ID_Subject = @ID_Discipline
        )
END

GO
SELECT dbo.avgScore(1) AS 'Среднее значение';

--Создать процедуру, формирующую список зачетов и экзаменов, которые
--необходимо сдать студентам указанной группы в указанный семестр (входные
--параметры – группа и семестр)

CREATE PROCEDURE Sessia (@ID_Group INT, @Semestr INT)
AS SELECT Name AS 'Название дисциплины',  
             Examination AS 'Тип сдачи'
FROM Subjects
     WHERE Subjects.Semester = @Semestr
          AND Subjects.Specialty = (SELECT Groups.Specialty
       FROM Groups
     WHERE Groups.ID = @ID_Group) 
     ORDER BY Examination desc
GO

EXECUTE Sessia 1, 2;

--DROP PROCEDURE Sessia