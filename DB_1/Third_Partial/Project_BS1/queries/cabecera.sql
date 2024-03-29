use DB1_Project

if object_id('cabecera') is not null
	drop table cabecera;

create table cabecera(
	nFactura int,
	cod_cliente int,
	cod_vendedor int,
	fecha datetime
);

---------------------------------------------------------------------------------
--  ADDING FKs FROM CLENTE.id AND VENDEDOR.id  ----------------------------------
---------------------------------------------------------------------------------

alter table cabecera
	add constraint FK_cod_clientes
	foreign key(cod_cliente)
	references cliente(id);

alter table cabecera
	add constraint FK_cod_vendedor
	foreign key(cod_vendedor)
	references vendedor(id);

---------------------------------------------------------------------------------
--  INSERTING FKs FROM CLENTE.id AND VENDEDOR.id  -------------------------------
---------------------------------------------------------------------------------

declare @contador as int
	set @contador = 1;

while (@contador <= 1000)
begin
	insert cabecera(cod_vendedor, cod_cliente, nFactura)
	values (
	ABS(CAST(NEWID() as binary(6)) % (select max(id) from vendedor)) + (select min(id) from vendedor),
	ABS(CAST(NEWID() as binary(6)) % (select max(id) from cliente)) + (select min(id) from cliente),
	ABS(CAST(NEWID() as binary(6)) % (select max(nFactura) from detalle_venta)) + (select min(nFactura) from detalle_venta)
	);
	set @contador = @contador + 1;
end

---------------------------------------------------------------------------------
--  INSERTING DATETIME  ---------------------------------------------------------
---------------------------------------------------------------------------------

DECLARE @counter INT = 1;

WHILE (@counter <= 1000)
BEGIN
	-- m - d - a
	UPDATE cabecera SET fecha = dateadd(day, abs(cast(newid() as binary(6)) % 7300) + 1, '2004-01-01');

    SET @counter = @counter + 1;
END

---------------------------------------------------------------------------------

select * from cabecera;
select min(year(fecha)) from cabecera;
select max(year(fecha)) from cabecera;