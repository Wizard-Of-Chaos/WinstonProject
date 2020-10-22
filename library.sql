CREATE TABLE Book (
    ISBN int,
    Title varchar(255),
    Author varchar(255),
    Call_Number varchar(255),
    Pages int
    );

CREATE TABLE Loans (
    ISBN int,
    Patron varchar(255)
    );

INSERT INTO Book (ISBN, Title, Author, Call_Number, Pages)
  VALUES (1234567, 'Cheese', 'Michael Eddins', '13131313', 90);

INSERT INTO Book 
  VALUES (8005882300, 'Empire', 'Grant Kelly', '8675309AB', 300);

INSERT INTO Loans
  VALUES (90604010, 'Big Chungus');

INSERT INTO Loans
  VALUES (345345894689, 'Epic Style');
