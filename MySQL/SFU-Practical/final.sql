USE master

GO
IF DB_ID('Final_pract') IS NOT NULL
    DROP DATABASE Final_pract;
IF DB_ID('Final_pract') IS NULL 
    CREATE DATABASE Final_pract;
GO
USE Final_pract
-- TABLES
CREATE TABLE Ticket	(--СДЕЛКИ(БИЛЕТЫ)
	ID				INT			NOT NULL IDENTITY(1, 1),
	ID_TicketOffice	INT			NULL				   ,
	ID_Trip			INT		    NULL				   ,
	Place			NVARCHAR(50)NULL				   ,
	Date_OfSale		DATE		NULL				   ,
	ID_Client		INT			NULL				   ,
)
CREATE TABLE ROUTEE (--РЕЙС
	ID				INT			NOT NULL IDENTITY(1, 1),
	WeeekDay		nvarchar(7)	NULL				   ,
    TimeDeparture   nvarchar(50)NULL				   ,
	TimeInWay       nvarchar(50)NULL		     	   ,
	ID_CityDeparture INT		NULL				   ,
	ID_CityInWay	 INT		NULL				   ,
	Price            money      NULL                   ,
	MIN_QuantityPlace INT       NULL				   ,
	CONSTRAINT PK_ROUTEE PRIMARY KEY NONCLUSTERED (ID) ,
)
CREATE TABLE Trip	(--ИНФОРМАЦИЯ
	ID				INT			NOT NULL IDENTITY(1, 1),
	ID_ROUTEE		INT			NULL				   ,
	ID_Bus	        INT			NULL				   ,
	ID_Driver	    INT	     	NULL				   ,
	DateArrival		DATE    	NULL				   ,
	CONSTRAINT PK_INFO PRIMARY KEY NONCLUSTERED (ID)   ,
)
CREATE TABLE BUS	(--АВТОБУСЫ
	ID				INT			NOT NULL IDENTITY(1, 1),
	Trademark	    nvarchar(50)NULL				   ,
	QuantityPalce   INT         NULL				   ,
	StateNumber   nvarchar(50)  NULL				   ,
	CONSTRAINT PK_BUS PRIMARY KEY NONCLUSTERED (ID)    ,
)
CREATE TABLE DRIVER (--ВОДИТЕЛИ
	ID				INT			NOT NULL IDENTITY(1, 1),
	NAMEE			NVARCHAR(20)NULL				   ,
	ID_CITY			INT			NULL				   ,
	CONSTRAINT PK_DRIVER PRIMARY KEY NONCLUSTERED (ID) ,
)
CREATE TABLE TicketOffice (--КАССЫ
	ID				INT			NOT NULL IDENTITY(1, 1),
	ID_CITY			INT			NULL				   ,
	Adres		NVARCHAR(50)Null				   ,
	CONSTRAINT PK_OFFICE PRIMARY KEY NONCLUSTERED (ID) ,
)
CREATE TABLE CITY	(--ГОРОДА
	ID				INT			NOT NULL IDENTITY(1, 1),
	Name			NVARCHAR(30)NULL				   ,
	CONSTRAINT PK_CITY PRIMARY KEY NONCLUSTERED (ID)   ,
)
CREATE TABLE CLIENT (--КЛИЕНТЫ
	ID				INT			NOT NULL IDENTITY(1, 1),
	Name			NVARCHAR(50)NULL				   ,
	Info			NVARCHAR(50)NULL				   ,
	CONSTRAINT PK_CLIENT PRIMARY KEY NONCLUSTERED (ID) ,
)
/*---VALUES---*/
	
INSERT INTO BUS
	VALUES
	('Икарус', 49, 'В768ОР'), 
	('Икарус', 49, 'В832ВЫ'), 
	('Мереседес', 13, 'З932АИ'), 
	('РАФ', 14, 'Т832ДЛ'), 
	('БУХАНКА', 25, 'У553КС'), 
	('ПАЗ', 25, 'О000ОО');

INSERT INTO CITY
	VALUES
	('Томск'), 
	('Красноярск'),
	('Новосибирск'),
	('Железногорск'),
	('Ачинск');

INSERT INTO CLIENT
	VALUES
	('Илья', 'Волков'),
	('Ксения', ' Полякова'),
	('Тимофей', ' Егоров'),
	('Никита', ' Яковлев'),
	('Анастасия', ' Зыкова'),
	('Ульяна', ' Орлова'),
	('Карина', ' Кудрявцева'),
	('Арсений', ' Новиков'),
	('Егор', ' Васильев'),
	('Никита', ' Павлов'),
	('Ева', ' Макарова'),
	('Анна', ' Захарова'),
	('Анастасия', ' Акимова'),
	('Надежда', ' Андреева'),
	('Станислав', ' Богданов'),
	('Виктория', ' Алексеева'),
	('Арсений', ' Винокуров'),
	('Аделина', ' Воробьева'),
	('Даниил', ' Анисимов'),
	('Даниил', ' Гладков'),
	('Владислава', ' Лобанова'),
	('Алексей', ' Горбунов'),
	('Денис', ' Филиппов'),
	('Кристина', ' Матвеева'),
	('Леонид', ' Рыбаков'),
	('Вероника', ' Симонова');

INSERT INTO DRIVER
	VALUES
	('Лёша', 1), 
	('Вася', 2), 
	('Даша', 2), 
	('Гоша', 3), 
	('Лера', 3), 
	('Ваня', 4), 
	('Саша', 5);

INSERT INTO ROUTEE
	VALUES
	('125', '13:12:00', '5:30:00', 1, 2, 1200, 15), 
	('125', '8:30:00', '5:50:00', 2, 1, 1200, 15), 
	('237', '11:00:00', '1:16:00', 2, 4, 600, 6), 
	('135', '13:12:00', '3:30:00', 2, 5, 800, 12), 
	('346', '13:12:00', '6:30:00', 1, 3, 1500, 20),
	('125', '17:14:00', '5:30:00', 3, 1, 1100, 15),  
	('24', '13:12:00', '6:15:00', 2, 3, 1500, 20); 

INSERT INTO TicketOffice
	VALUES
	(1, 'Студгородок'),
	(2, 'Академгородок'),
	(3, 'Ул Борисова'),
	(4, 'Автовокзал'),
	(5, 'ЖД вокзал');

INSERT INTO Trip
	VALUES 
	(1, 1, 1, '01-01-2014'),
	(2, 2, 2, '02-02-2014'),
	(3, 3, 3, '01-01-2015'),
	(4, 4, 4, '13-12-2014'),
	(5, 5, 5, '01-01-2014'),
	(6, 6, 6, '01-01-2016'),
	(3, 2, 6, '12-03-2014'),
	(4, 3, 7, '04-12-2015');


INSERT INTO Ticket
	VALUES
	(1, 1, 1, '01-01-2014', 1),
	(1, 1, 2, '01-01-2014', 2),
	(1, 1, 3, '01-01-2014', 3),
	(1, 1, 4, '01-01-2014', 4),
	(1, 1, 5, '01-01-2014', 5),
	(1, 1, 6, '01-01-2014', 6),
	(1, 1, 7, '01-01-2014', 7),
	(1, 1, 8, '01-01-2014', 8),
	(1, 1, 9, '01-01-2014', 9),
	(1, 1, 10, '01-01-2014', 10),
	(1, 1, 11, '01-01-2014', 11),
	(1, 1, 12, '01-01-2014', 12),
	(1, 1, 13, '01-01-2014', 13),
	(1, 1, 14, '01-01-2014', 14),
	(1, 1, 15, '01-01-2014', 15),
	(1, 1, 16, '01-01-2014', 16),
	
	(2, 2, 1, '01-06-2014', 17),
	(2, 2, 2, '01-06-2014', 18),
	(2, 2, 3, '01-06-2014', 19),
	(2, 2, 4, '01-06-2014', 20),
	(2, 2, 5, '01-06-2014', 21),
	(2, 2, 6, '01-06-2014', 22),
	(2, 2, 7, '01-06-2014', 23),
	(2, 2, 8, '01-06-2014', 1),
	(2, 2, 9, '01-06-2014', 2),
	(2, 2, 10, '01-06-2014', 3),
	(2, 2, 11, '01-06-2014', 4),
	(2, 2, 12, '01-06-2014', 5),
	(2, 2, 13, '01-06-2014', 6),
	(2, 2, 14, '01-06-2014', 7),
	(2, 2, 15, '01-06-2014', 8),
	(2, 2, 16, '01-06-2014', 9),
	(2, 2, 17, '01-06-2014', 10),

	(3, 3, 1, '01-06-2015', 17),
	(3, 3, 2, '01-06-2015', 18),
	(3, 3, 3, '01-06-2015', 19),
	(3, 3, 4, '01-06-2015', 20),
	(3, 3, 5, '01-06-2015', 21),
	(3, 3, 6, '01-06-2015', 22),
	(3, 3, 7, '01-06-2015', 23),
	(3, 3, 8, '01-06-2015', 1),
	(3, 3, 9, '01-06-2015', 2),
	(3, 3, 10, '01-06-2015', 3),
	(3, 3, 11, '01-06-2015', 4),
	(3, 3, 12, '01-06-2015', 5),
	(3, 3, 13, '01-06-2015', 6),
	(3, 3, 14, '01-06-2015', 7),
	(3, 3, 15, '01-06-2015', 8),
	(3, 3, 16, '01-06-2015', 9),
	(3, 3, 17, '01-06-2015', 10),

	(4, 4, 1, '01-01-2015', 13),
	(4, 4, 2, '01-01-2015', 14),
	(4, 4, 3, '01-01-2015', 15),
	(4, 4, 4, '01-01-2015', 20),
	(4, 4, 5, '01-01-2015', 21),
	(4, 4, 6, '01-01-2015', 22),
	(4, 4, 7, '01-01-2015', 23),
	(4, 4, 8, '01-01-2015', 1),
	(4, 4, 9, '01-01-2015', 2),
	(4, 4, 10, '01-01-2015', 3),
	(4, 4, 11, '01-01-2015', 4),
	(4, 4, 12, '01-01-2015', 5),
	(4, 4, 13, '01-01-2015', 6),
	(4, 4, 14, '01-01-2015', 7),
	(4, 4, 15, '01-01-2015', 8),
	(4, 4, 16, '01-01-2015', 9),
	(4, 4, 17, '01-01-2015', 10),

	(5, 5, 1, '01-06-2016', 17),
	(5, 5, 2, '01-06-2016', 18),
	(5, 5, 3, '01-06-2016', 19),
	(5, 5, 4, '01-06-2016', 20),
	(5, 5, 5, '01-06-2016', 21),
	(5, 5, 6, '01-06-2016', 22),
	(5, 5, 7, '01-06-2016', 23),
	(5, 5, 8, '01-06-2016', 13),
	(5, 5, 9, '01-06-2016', 24),
	(5, 5, 10, '01-06-2016', 16),
	(5, 5, 11, '01-06-2016', 4),
	(5, 5, 12, '01-06-2016', 5),
	(5, 5, 13, '01-06-2016', 6),
	(5, 5, 14, '01-06-2016', 7),
	(5, 5, 15, '01-06-2016', 8),
	(5, 5, 16, '01-06-2016', 9),
	(5, 5, 17, '01-06-2016', 10);

-- Driver коннект
ALTER TABLE [dbo].[Driver]  WITH CHECK ADD  CONSTRAINT [FK_Driver_City] FOREIGN KEY([ID_City])
REFERENCES [dbo].[City] ([ID])
GO

ALTER TABLE [dbo].[Driver] CHECK CONSTRAINT [FK_Driver_City]
GO

-- Routee коннект
ALTER TABLE [dbo].[ROUTEE]  WITH CHECK ADD  CONSTRAINT [FK_Routee_City] FOREIGN KEY([ID_CityDeparture])
REFERENCES [dbo].[City] ([ID])
GO

ALTER TABLE [dbo].[Routee] CHECK CONSTRAINT [FK_Routee_City]
GO

ALTER TABLE [dbo].[Routee]  WITH CHECK ADD  CONSTRAINT [FK_Routee_City1] FOREIGN KEY([ID_CityInWay])
REFERENCES [dbo].[City] ([ID])
GO

ALTER TABLE [dbo].[Routee] CHECK CONSTRAINT [FK_Routee_City1]
GO

-- TicketOffice коннект
ALTER TABLE [dbo].[TicketOffice]  WITH CHECK ADD  CONSTRAINT [FK_TicketOffice_City] FOREIGN KEY([ID_City])
REFERENCES [dbo].[City] ([ID])
GO

ALTER TABLE [dbo].[TicketOffice] CHECK CONSTRAINT [FK_TicketOffice_City]
GO

-- Trip коннект
ALTER TABLE [dbo].[Trip]  WITH CHECK ADD  CONSTRAINT [FK_Trip_Bus] FOREIGN KEY([ID_Bus])
REFERENCES [dbo].[Bus] ([ID])
GO

ALTER TABLE [dbo].[Trip] CHECK CONSTRAINT [FK_Trip_Bus]
GO

ALTER TABLE [dbo].[Trip]  WITH CHECK ADD  CONSTRAINT [FK_Trip_Driver] FOREIGN KEY([ID_Driver])
REFERENCES [dbo].[Driver] ([ID])
GO

ALTER TABLE [dbo].[Trip] CHECK CONSTRAINT [FK_Trip_Driver]
GO

ALTER TABLE [dbo].[Trip]  WITH CHECK ADD  CONSTRAINT [FK_Trip_Routee] FOREIGN KEY([ID_Routee])
REFERENCES [dbo].[Routee] ([ID])
GO

ALTER TABLE [dbo].[Trip] CHECK CONSTRAINT [FK_Trip_Routee]
GO

-- Ticket коннект
ALTER TABLE [dbo].[Ticket]  WITH CHECK ADD  CONSTRAINT [FK_Ticket_Client] FOREIGN KEY([ID_Client])
REFERENCES [dbo].[Client] ([ID])
GO

ALTER TABLE [dbo].[Ticket] CHECK CONSTRAINT [FK_Ticket_Client]
GO

ALTER TABLE [dbo].[Ticket]  WITH CHECK ADD  CONSTRAINT [FK_Ticket_TicketOffice] FOREIGN KEY([ID_TicketOffice])
REFERENCES [dbo].[TicketOffice] ([ID])
GO

ALTER TABLE [dbo].[Ticket] CHECK CONSTRAINT [FK_Ticket_TicketOffice]
GO

ALTER TABLE [dbo].[Ticket]  WITH CHECK ADD  CONSTRAINT [FK_Ticket_Trip] FOREIGN KEY([ID_Trip])
REFERENCES [dbo].[Trip] ([ID])
GO

ALTER TABLE [dbo].[Ticket] CHECK CONSTRAINT [FK_Ticket_Trip]
GO

--1

SELECT Routee.TimeDeparture AS [Время отпавления],
       Routee.Price AS Цена
	FROM Routee
		JOIN City a
			ON Routee.ID_CityDeparture = a.ID
		JOIN City b
			ON Routee.ID_CityInWay = b.ID
	WHERE (a.Name = 'Новосибирск' AND b.Name = 'Томск');

--2

SELECT SUM(Routee.Price) AS [Доход в кассе 2]
	FROM Ticket
		JOIN Trip
		 ON Ticket.ID_Trip = Trip.ID 
		JOIN Routee 
		 ON Routee.ID = Trip.ID_Routee
	WHERE Ticket.ID_TicketOffice = 2;

--3

SELECT TicketOffice.ID AS Касса, 
       SUM(Routee.Price) AS Цена
	FROM TicketOffice
		JOIN Ticket 
		 ON TicketOffice.ID = Ticket.ID_TicketOffice
		JOIN Trip 
		 ON ticket.ID_Trip = Trip.ID
		JOIN Routee 
		 ON Trip.ID_Routee = Routee.ID
		JOIN city 
		ON TicketOffice.ID_City = City.ID
	WHERE (City.Name = 'Томск')
	GROUP BY TicketOffice.ID;

--4

IF OBJECT_ID('GetDriverCount') IS NOT NULL  
    DROP PROC GetDriverCount;  
GO

CREATE PROC GetDriverCount(@id INT) 
AS 
    SELECT COUNT(ID_Driver) AS 'Число рейсов',
           Driver.NAMEE AS Имя
      FROM Trip 
        JOIN Routee 
          ON Routee.ID = Trip.ID_Routee
        JOIN driver 
          ON Driver.ID = Trip.ID_Driver
     WHERE ID_Driver = @id AND DateArrival >= DATEADD(YEAR, -1, 01-06-2016)
     GROUP BY Driver.NAMEE;
RETURN
GO

EXEC GetDriverCount 5;
GO

--5

IF OBJECT_ID('PutDriver') IS NOT NULL  
    DROP TRIGGER PutDriver;  
GO

CREATE TRIGGER PutDriver 
    ON Trip FOR INSERT 
    AS 
    BEGIN 
        IF EXISTS (SELECT * FROM inserted 
	         JOIN Driver 
               ON inserted.ID_Driver= Driver.ID 
	         JOIN Routee 
               ON inserted.ID_Routee = Routee.ID 
            WHERE Routee.ID_CityDeparture != Driver.ID_City) 
        BEGIN 
            PRINT N'Нельзя назначить водителя. Водитель не живет в городе отправления маршрута.' 
            ROLLBACK TRAN 
        END 
    END 
GO

INSERT INTO Trip VALUES (1, 2, 1, '01-01-2022'); -- Рейс на маршрут Томск - Красноярск, пытаемся назначить Гену из Красноярска
GO

--6 

IF OBJECT_ID('CanPlace', 'TRIGGER') IS NOT NULL  
    DROP TRIGGER CanPlace;  
GO

CREATE TRIGGER CanPlace
    ON dbo.Ticket FOR INSERT
    AS DECLARE @PlaceNumber INT
        SELECT @PlaceNumber = Place FROM inserted
    BEGIN
        IF (SELECT COUNT(ticket.ID) FROM dbo.Ticket 
              JOIN inserted ON Ticket.ID_Trip = inserted.ID_Trip 
             WHERE dbo.Ticket.[Place] = @PlaceNumber) > 1
        BEGIN
            ROLLBACK TRAN
            PRINT N'Место занято'
        END
    END 
GO

INSERT INTO TICKET VALUES (1, 1, 18, '22-12-2022', 3);

--7

SELECT Bus.Trademark AS [Марка авто],
       COUNT(Trip.ID) AS [Количество рейсов]
	FROM trip
		JOIN bus 
		ON bus.ID = Trip.ID_Bus
	WHERE (Bus.Trademark = 'ПАЗ' OR bus.Trademark = 'Икарус')
	GROUP BY Bus.Trademark;
GO

--8

IF OBJECT_ID('FreePlaces') IS NOT NULL  
    DROP PROC FreePlaces;  
GO

CREATE PROCEDURE FreePlaces(@tripID int) 
AS
    BEGIN
		PRINT('Свободные места')
        DECLARE @place int = 1;
        WHILE (@place <= (SELECT Bus.QuantityPalce
                            FROM Bus
                           WHERE ID = (SELECT Trip.ID_Bus
                                          FROM Trip
                                         WHERE ID = @tripID)))
        BEGIN
            IF (@place NOT IN (SELECT Ticket.Place
                                 FROM Ticket
                                WHERE Ticket.ID_Trip = @tripID))
                PRINT(@place)	
                SET @place = @place + 1;
        END
    END
RETURN
GO

EXECUTE Freeplaces 1; -- Сколько свободных мест в Буханке (в ней всего 25 мест, заплоненно 17)

GO

--9

SELECT TicketOffice.ID AS Касса,
       COUNT(Ticket.ID) AS [Количество проданных билетов]
FROM TicketOffice
    JOIN Ticket 
      ON TicketOffice.ID = Ticket.ID_TicketOffice
GROUP BY TicketOffice.ID

--10

SELECT avg(Price) as [Средняя цена билета] FROM ROUTEE;

GO

--11

SELECT * FROM ROUTEE
	where Price > (SELECT avg(Price) FROM ROUTEE);

--12

DELETE FROM Ticket
	WHERE Ticket.ID = 1;

--13

SELECT Trip.DateArrival,Trip.ID_Bus,Trip.ID_Driver,Trip.ID_ROUTEE,PRICE,TimeInWay FROM ROUTEE
	JOIN
	Trip on Trip.ID_ROUTEE = ROUTEE.ID
	where ROUTEE.ID_CityDeparture = 1;

--14

SELECT COUNT(Ticket.ID) AS [Число билетов]
	FROM Ticket
		JOIN Trip 
			ON Trip.ID = Ticket.ID_Trip
		JOIN Routee 
			ON Routee.ID = Trip.ID_Routee
			where (ROUTEE.ID_CityDeparture = (select distinct id from city where Name = 'Томск')
			and ROUTEE.ID_CityInWay = (select distinct id from city where Name = 'Новосибирск')
			and (DATEPART(YEAR, trip.DateArrival) IN (2014, 2015)));

--15

UPDATE Trip
	SET Trip.ID_Bus = 2 WHERE Trip.ID = 1
	SELECT * FROM Trip;
GO

--16

SELECT * FROM Routee
    WHERE Routee.ID_CityDeparture = (SELECT Driver.ID_City
                                     FROM Driver
                                     WHERE Driver.ID = 1) AND Routee.MIN_QuantityPlace <= 30 
GO

--17

UPDATE Bus 
	SET QuantityPalce = QuantityPalce + 3
    WHERE Bus.ID = 5;