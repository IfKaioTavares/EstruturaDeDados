Objetivo:
Desenvolver um sistema escolar em linguagem C utilizando conceitos de listas encadeadas para gerenciar alunos, turmas, professores, cursos e matrículas.
Funcionalidades Principais:
	Cadastro de Alunos:
●	Permitir o cadastro de alunos com informações como matrícula, nome, idade, etc.
●	Manter uma lista encadeada dinâmica de alunos.
	Cadastro de Cursos:
●	Permitir o registro de cursos com detalhes como nome do curso, carga horária, etc.
●	Manter uma lista encadeada dinâmica de cursos.
	Matrícula em Cursos:
●	Permitir a matrícula de um aluno em um ou mais cursos.
●	Estabelecer essa relação entre aluno e curso através de listas encadeadas.
	Cadastro de Turmas:
●	Possibilitar o cadastro de turmas com informações como identificador, disciplina, etc.
●	Manter uma lista encadeada dinâmica de turmas.
	Designação de Professores:
●	Permitir a atribuição de professores a turmas específicas.
●	Relacionar professores e turmas através de listas encadeadas.
	Listagens:
●	Mostrar a lista de alunos por turma.
●	Listar cursos disponíveis.
●	Exibir os professores com suas turmas.
Estruturas de Dados:
	Aluno:
●	Matrícula
●	Nome
●	Lista encadeada de cursos matriculados
	Curso:
●	Nome do curso
●	Carga horária
●	Próximo curso na lista
	Turma:
●	Identificador
●	Lista encadeada de alunos matriculados
●	Professor responsável
	Professor:
●	Nome
●	Disciplina lecionada
●	Lista encadeada de turmas ministradas
Orientações Gerais:
●	Implementar as operações em funções separadas para cada funcionalidade.
●	Garantir a liberação de memória correta após o uso das estruturas.
●	Criar um menu interativo para permitir a interação com o sistema.
●	Documentar o código de forma clara, incluindo comentários explicativos.
