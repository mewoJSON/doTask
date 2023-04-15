

CREATE TABLE IF NOT EXISTS Tasks (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL DEFAULT 'New  Task',
    date TEXT NOT NULL,
    type TEXT CHECK ( type IN ('CHECKBOX', 'SCORE') ) NOT NULL DEFAULT 'CHECKBOX',
    completed BOOL NOT NULL DEFAULT false,
    note TEXT,
    score INTEGER NOT NULL DEFAULT 0
);

INSERT INTO Tasks (name, date, type, completed, note, score) VALUES
("Do the dishes.", "3 15", "CHECKBOX", false, NULL, 0),
("Doctor appointment", "5 24", "CHECKBOX", false, "Need to have a physical and get my left arm checked out :(", 0),
("Finish the networking project", "3 13", "CHECKBOX", true, NULL, 0),
("Ace the calculus exam!", "2 15", "SCORE", true, "I feel like I did really good on the exam!", 10),
("Sad Day! ;(", "3 1", "SCORE", false, "Dear diary: i was sad today...", 1),
("Just a typical day", "1 8", "SCORE", false, NULL, 7);