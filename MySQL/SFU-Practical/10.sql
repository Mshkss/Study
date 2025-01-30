USE Decanat

--1
INSERT Groups
	VALUES (' »20-10', 3, 6, 5);

-- 2
UPDATE Students
	SET [ID_Group] = 5 WHERE [ID_Group] = 3;

--3
UPDATE Groups
	SET [Leader] = (SELECT [Leader] FROM Groups WHERE ID = 4),
		[Curator] = (SELECT [Curator] FROM Groups WHERE ID = 4)
	WHERE Groups.ID = 5;

--4
DELETE FROM Groups WHERE ID = 3;
