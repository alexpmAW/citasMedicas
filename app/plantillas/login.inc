<?php ob_start(); ?>
<form action="" method="post">
    <label for="numColegiado">Numero de colegiado:</label>
    <input type="password" name="numColegiado" id="numColegiado">

    <input type="submit" value="Ingresar" name="ok">
</form>


<?php $contenido = ob_get_clean();
include 'base.php' ?>