<?php
class MedicoRepositorio
{

    public function existMedicoByNumColegiado(string $numColegiado)
    {
        $sql = 'SELECT numColegiado
                    FROM medico
                    WHERE numColegiado = :numColegiado';
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(':numColegiado', $numColegiado);
            $snt->execute();
            $fila = $snt->fetch(\PDO::FETCH_ASSOC);
            return !empty($fila);
        } catch (\PDOException $ex) {
            throw $ex;
        } finally {
            if (isset($snt)) {
                unset($snt);
            }
            if (isset($con)) {
                unset($con);
            }
        }
    }
    public function getConsultasMedico(string $numColegiado)
    {
        $sql = 'SELECT fcita,hcita,apellido+ \',\'+nombre as paciente, fnacimiento,
                        genero = case hombre 
                                        when 1 then Hombre 
                                        when 0 then Mujer end,
                        observaciones
                    FROM cita as c inner join paciente as p on c.idpaciente = p.idpaciente 
                        and idMedico = (select idmedico from medico WHERE numcolegiado = :numcolegiado)
                        and (fCita = getdate() or fcita = dateadd(day,1,getdate()))';
        require_once __DIR__ . '/../../core/conexionBd.inc';
        try {
            $con = (new ConexionBd())->getConexion();
            $snt = $con->prepare($sql);
            $snt->bindValue(':numColegiado', $numColegiado);
            $snt->execute();
            $fila = $snt->fetchAll(\PDO::FETCH_ASSOC);
            return $fila;
        } catch (\PDOException $ex) {
            throw $ex;
        } finally {
            if (isset($snt)) {
                unset($snt);
            }
            if (isset($con)) {
                unset($con);
            }
        }
    }
}
