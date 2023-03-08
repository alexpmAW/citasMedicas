<?php
// Ejemplo de controlador para página home de la aplicación
class DefaultController
{
  public function inicio()
  {
    require __DIR__ . '/../../app/plantillas/inicio.php';
  }
  public function consultarPacientes()
  {
    if (isset($_POST['ok'])) {
      require_once __DIR__ . '/../Repositorio/MedicoRepositorio.inc';
      if ((new MedicoRepositorio())->existMedicoByNumColegiado($_POST['numColegiado'])) {
        $_SESSION['medico'] = true;
        $_SESSION['numColegiado'] = $_POST['numColegiado'];
      }
    }
    require __DIR__ . '/../../app/plantillas/login.inc';
  }
}
