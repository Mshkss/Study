use Decanat;
/* �������� � ������������� ���������, ��������� ������ �� ��������. �������
�.�.�., ����� ������ � �������. ������������ �� ��������� � �������. */

GO
IF (EXISTS (select * FROM sys.views where name = 'GroupList')) 
	begin
		DROP VIEW GroupList
	end
GO 
CREATE VIEW GroupList AS
	SELECT Studying.[Gradebook number] AS '�������� ������',
		   Studying.Mark AS '������',
		   Subjects.Semester AS '�������',
		   Subjects.Specialty AS '�������������'
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
	SELECT GroupList.[�������� ������] AS '�������� ������',
		   SUM(CASE WHEN GroupList.������ = '�����' THEN 1
					WHEN GroupList.������ = '�������' THEN 1
					--when grouplist.������ = '������' THEN 0
					ELSE 0
			   END) AS '����� ������',
		   GroupList.������� AS '�������',
		   GroupList.������������� AS '�������������'
	FROM GroupList
	GROUP BY GroupList.[�������� ������], GroupList.�������, GroupList.�������������

GO
SELECT * FROM Scores


GO
IF (EXISTS (select * FROM sys.views where name = 'GoodStudents')) 
	begin
		DROP VIEW GoodStudents
	end
GO
CREATE VIEW GoodStudents AS
	SELECT SURNAME AS ' �������',
		   STUDENTS.[First name] AS '���',
		   PATRONYMIC AS '��������',
		   GROUPS.Name AS '�������� ������',
		   Scores.������� AS '�������'
	FROM STUDENTS
	JOIN GROUPS ON STUDENTS.ID_GROUP = GROUPS.ID 
	JOIN Scores ON STUDENTS.[Gradebook number] = Scores.[�������� ������]
	WHERE Scores.[����� ������] = (SELECT COUNT(Subjects.ID) FROM Subjects
								 WHERE Subjects.Specialty = Scores.�������������
								 AND  Subjects.SEMESTER = Scores.�������)

GO
SELECT * FROM GoodStudents