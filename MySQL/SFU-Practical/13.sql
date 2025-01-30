USE Decanat;

--��� �������� ��������� ����������, ������� �� ���� ������� ����������, ��
--������� ���� �� ���� ������� ������� ������� (�����).


IF OBJECT_ID('discDelete', 'TRIGGER') IS NOT NULL  
    DROP TRIGGER discDelete;  
GO

CREATE TRIGGER discDelete --��������
	ON Subjects INSTEAD OF DELETE 
	AS IF (SELECT count(Studying.ID_Subject)
		FROM Studying
			Where Studying.ID_Subject IN (SELECT id From deleted)) <> 0
		BEGIN
			ROLLBACK TRAN
			PRINT N'������! ��� ���������� ������� ������!'
		END 
GO

DELETE FROM Subjects	
	WHERE id = 1;
GO

--��������� ������ �������� � ��������� ������. ���� ����������� �� ���������
--�������� ������� �� ������� � ���� ������, ������� �������� ����������.

IF OBJECT_ID('updLeader', 'TRIGGER') IS NOT NULL  
    DROP TRIGGER updLeader;  
GO

CREATE TRIGGER updLeader --����������
	ON Groups
		FOR UPDATE
			AS BEGIN
				IF (SELECT Inserted.Leader FROM Inserted) NOT IN
					(SELECT Students.[Gradebook number]
						FROM Students
							WHERE Students.ID_Group in (SELECT Inserted.id FROM Inserted))
				BEGIN
					ROLLBACK TRAN
					PRINT N'������! ������� �� ������� � ������ ������!'
				END
			END

GO

UPDATE Groups
SET Groups.Leader = 15
WHERE Groups.id = 4
GO

--�� ��������� �������� ���������� � ������� �������� (��� ������), ����
--���������� �� ������������� ������������� ��������.


IF OBJECT_ID('insStuding', 'TRIGGER') IS NOT NULL  
    DROP TRIGGER insStuding;  
GO

CREATE TRIGGER insStuding --����������
	ON Studying
	FOR INSERT
	AS 
	BEGIN
		DECLARE @zachetka INT
		SELECT @zachetka = (SELECT [Gradebook number] FROM Inserted)
		IF (SELECT d.Specialty 
				FROM Subjects d
				JOIN Inserted i ON i.ID_Subject = d.id) <>
			(SELECT g.Specialty
				FROM Groups g
					WHERE g.id = (SELECT s.ID_Group 
									FROM Students s 
									JOIN Inserted i ON s.[Gradebook number] = i.[Gradebook number]))
		BEGIN
			ROLLBACK TRAN
			PRINT N'������! ������� �������� ������ �������� ��� ����������!'
		END
	 END

GO

INSERT Studying
	VALUES (13, 1, '2023.05.26', '�����');
GO
