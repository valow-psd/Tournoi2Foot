BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS teams (
	id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
	nom_equipe VARCHAR(20),
	victoires INT NOT NULL DEFAULT 0,
	nuls INT NOT NULL DEFAULT 0,
	defaites INT NOT NULL DEFAULT 0
);
INSERT INTO teams (id,nom_equipe,victoires,nuls,defaites) VALUES (1,'Paris SG',1,1,1);
INSERT INTO teams (id,nom_equipe,victoires,nuls,defaites) VALUES (2,'Man. United',2,1,0);
INSERT INTO teams (id,nom_equipe,victoires,nuls,defaites) VALUES (3,'Leeds',0,0,3);
INSERT INTO teams (id,nom_equipe,victoires,nuls,defaites) VALUES (4,'AS Saint-Etienne',2,1,0);
INSERT INTO teams (id,nom_equipe,victoires,nuls,defaites) VALUES (5,'RB Leipzig',3,0,0);
COMMIT;


SELECT nom_equipe, 


CREATE USER 'ekip'@'localhost' IDENTIFIED BY 'lefootccool';   
GRANT ALL PRIVILEGES ON * . * TO 'ekip'@'localhost';  
FLUSH PRIVILEGES;

mysql -u ekip -p

CREATE DATABASE teams_ekip;

use teams_ekip;

CREATE TABLE IF NOT EXISTS teams (
	id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
	nom_equipe VARCHAR(20),
	victoires INT NOT NULL DEFAULT 0,
	nuls INT NOT NULL DEFAULT 0,
	defaites INT NOT NULL DEFAULT 0
);
INSERT INTO teams (id,nom_equipe,victoires,nuls,defaites) VALUES (1,'Paris SG',1,1,1);
INSERT INTO teams (id,nom_equipe,victoires,nuls,defaites) VALUES (2,'Man. United',2,1,0);
INSERT INTO teams (id,nom_equipe,victoires,nuls,defaites) VALUES (3,'Leeds',0,0,3);
INSERT INTO teams (id,nom_equipe,victoires,nuls,defaites) VALUES (4,'AS Saint-Etienne',2,1,0);
INSERT INTO teams (id,nom_equipe,victoires,nuls,defaites) VALUES (5,'RB Leipzig',3,0,0);

exit;

