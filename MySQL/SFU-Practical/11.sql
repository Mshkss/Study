use Decanat;

--������� �������, ������������ ������� ��� �� ��������� ����������.
--�������� ������������� ����������, ��� ������� �������� (��������,
--ID_Disciplin), ������� ���������� ������������ �������� �������� ����� �����
--���� ���������, ��������� �������

--������� �������� �� if ��� � 9 ������::
GO
DROP FUNCTION avgScore;

GO
CREATE FUNCTION avgScore (@ID_Discipline INT)
    RETURNS FLOAT
BEGIN
RETURN (
        SELECT CAST(SUM((CASE 
                         WHEN Studying.Mark = '�������' then 5 
                         WHEN Studying.Mark = '������' then 4 
                         WHEN Studying.Mark = '�����������������' then 3
						 WHEN Studying.Mark = '�����' then 1
						 WHEN Studying.Mark = '�������' then 0
	                      END)) AS FLOAT) / COUNT(Studying.Mark)
          FROM decanat.dbo.Studying 
              WHERE Studying.ID_Subject = @ID_Discipline
        )
END

GO
SELECT dbo.avgScore(1) AS '������� ��������';

--������� ���������, ����������� ������ ������� � ���������, �������
--���������� ����� ��������� ��������� ������ � ��������� ������� (�������
--��������� � ������ � �������)

CREATE PROCEDURE Sessia (@ID_Group INT, @Semestr INT)
AS SELECT Name AS '�������� ����������',  
             Examination AS '��� �����'
FROM Subjects
     WHERE Subjects.Semester = @Semestr
          AND Subjects.Specialty = (SELECT Groups.Specialty
       FROM Groups
     WHERE Groups.ID = @ID_Group) 
     ORDER BY Examination desc
GO

EXECUTE Sessia 1, 2;

--DROP PROCEDURE Sessia